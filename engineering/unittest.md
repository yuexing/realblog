## Googletest

<pre>
$ c++ -isystem ../include -g -Wall -Wextra -pthread -c ../samples/sample1.cc
$ c++ -isystem ../include -g -Wall -Wextra -pthread -c ../samples/sample1_unittest.cc
$ c++ -isystem ../include -I.. -g -Wall -Wextra -pthread -c \
            ../src/gtest-all.cc
$ c++ -isystem ../include -I.. -g -Wall -Wextra -pthread -c \
            ../src/gtest_main.cc
$ ar rv gtest_main.a gtest-all.o gtest_main.o
$ c++ -isystem ../include -g -Wall -Wextra -pthread -lpthread sample1.o sample1_unittest.o gtest_main.a -o sample1_unittest
</pre>

<pre>
#include "gtest/gtest.h"

TEST(Test, test_1) {
	EXPECT_EQ(2, 1+1);
	EXPECT_FALSE(3 == 1+1);
}

class VectorTest : public testing::Test {
protected:
	VectorTest() {
		std::cout &lt;&lt; "VectorTest::" &lt;&lt; __FUNCTION__ &lt;&lt; std::endl;
	}
	virtual ~VectorTest() {
		std::cout &lt;&lt; "VectorTest::" &lt;&lt; __FUNCTION__ &lt;&lt; std::endl;
	}
	virtual void SetUp() override {
		std::cout &lt;&lt; "VectorTest::" &lt;&lt; __FUNCTION__ &lt;&lt; std::endl; 
	}

	virtual void TearDown() override {
		std::cout &lt;&lt; "VectorTest::" &lt;&lt; __FUNCTION__ &lt;&lt; std::endl; 
	}

	std::vector<char> m_v;
};

TEST_F(VectorTest, test_1) {
	EXPECT_EQ(0, m_v.size());
	m_v.push_back(1);
}

TEST_F(VectorTest, test_2) {
	EXPECT_EQ(0, m_v.size());
}
</pre>

### Googlemock

<pre>
$ c++ -isystem googletest/include -Igoogletest -pthread -c googletest/src/gtest-all.cc
$ c++ -isystem googletest/include -I googlemock/include -I googlemock -pthread -c googlemock/src/gmock-all.cc 
$ ar -rv libgmock.a gtest-all.o gmock-all.o
$ c++ -isystem googletest/include -isystem googlemock/include -pthread googlemock/make/test.cc libgmock.a -o test 
$ ./test
</pre>

<pre>
#include "gmock/gmock.h"

class Turtle {
public:
  virtual ~Turtle() {}
  virtual void PenDown() = 0;
};

class MockTurtle : public Turtle {
public:
  MOCK_METHOD0(PenDown, void());
};

class Painter {
public:
	Painter(Turtle* t): m_t(t) {}

	bool DrawCircle() {
		m_t->PenDown();
		return true;
	}
private:
	Turtle* m_t;
};

TEST(PainterTest, CanDrawSomething) {
  MockTurtle turtle;                          
  EXPECT_CALL(turtle, PenDown())             
      .Times(testing::AtLeast(1));

  Painter painter(&amp;turtle);                   

  EXPECT_TRUE(painter.DrawCircle());
}                                             

int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleMock(&amp;argc, argv);
  return RUN_ALL_TESTS();
}
</pre>

### Environment

<pre>
class FooEnvironment {
 public:
  virtual ~Environment() {}
  // Override this to define how to set up the environment.
  virtual void SetUp() {}
  // Override this to define how to tear down the environment.
  virtual void TearDown() {}
};
int main(int argc, char** argv) {
	::testing::Environment* const foo_env = ::testing::AddGlobalTestEnvironment(new FooEnvironment);
}
</pre>