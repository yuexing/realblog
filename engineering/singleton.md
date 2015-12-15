## Singleton

### Why it's bad?

- dependency btw modules and within the module is hard to see. 
	- hard to mock up dependency, eg. test, pull a moudle out
	- shutting down is very fragile. Shutting down crash is reported in every release, 
  - logout is impossible to be implemented confidently clean. if the object is not cleaned up, then the user'll probably be messed up with the states of the last user

### How to inject instead?

  - generally, each module has a Service classes. They'll hold the strong reference of the objects in the module.

  <pre>
  // init
  std::shared_ptr<xmpp::UserInfo> user_info(new xmpp::UserInfo(/*captured by weak_ptr*/user_settings ...));
  m_user_service.reset(new accountinfo::UserInfoServiceImpl(/*captured by shared_ptr*/user_info ...);

  // UserInfoService
  UserInfoServiceImpl(const std::shared_ptr<xmpp::UserInfo>& user_info,
                      const std::shared_ptr<xmpp::UserSettings>& user_settings,
                      const std::shared_ptr<cloud::CloudStorageManagerInterface>& cloud_storage_manager,
                      const std::weak_ptr<sgiggle::contacts::ContactManager>& contact_manager)
    : m_user_info(user_info), m_user_settings(user_settings), m_cloud_storage_manager(cloud_storage_manager), m_contact_manager(contact_manager) {};

  std::shared_ptr<xmpp::UserInfo> m_user_info;
  std::shared_ptr<xmpp::UserSettings> m_user_settings;
  std::shared_ptr<cloud::CloudStorageManagerInterface> m_cloud_storage_manager;
  std::weak_ptr<sgiggle::contacts::ContactManager> m_contact_manager;
  </pre>
  
  - others generally will hold weak reference for the injected object, and use by lock

  <pre>
  // UserInfo
  UserInfo(const std::weak_ptr<UserSettings>& user_settings,
           const std::weak_ptr<tango::auth::AuthTokenManager>& authtoken_manager,
           const std::weak_ptr<tango::httpme::facilitator_response_dispatcher>& facilitator_response_dispatcher);

  // use by lock, if the lock returns null, this indiates the shutdown, then simply return
  std::string UserInfo::getPureDisplayNameImpl() const
  {
    auto contact_manager = m_contact_manager.lock();
    if(! contact_manager) {
      return "";
    }
    // ... use contact_manager ...
  }
  </pre>

  - also, always post the weak ref to a thread. This requires std::enable_shared_from_this<T>

  <pre>
  // ContactManager
  class ContactManager : public std::enable_shared_from_this<ContactManager>, public ContactPersistentProperties {};

  void ContactManager::onAcmeContactFilterMessage(std::string id, std::string msg)
  {
    std::weak_ptr<ContactManager> wths(shared_from_this());
    tango::util::post_impl_in_thread(media_engine_manager->getProcessorImpl(), [wths, ...]() {
    if(auto sths = wths.lock()) {
      // ... ...
    });
  }
  </pre>

### Inject all the object?

We have so many classes, it's too much to inject all. So:

- If the object has states, it needs to be injected.
- If the object has member objects with states, it needs to be injected.

Make the rule a little loose:

- Only the user-related state is considered as the state. eg. the app is foreground or not is not a state and thus app_state_mgr can still be a singleton