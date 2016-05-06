## Distributed System

### Terms:

- Node, Super Node, Bootstrap Node
- Available: can be used
- Reliable: time_btw_failure/(time_btw_failure + time_btw_repair)
- Fault-tolerant: 

### Timing: 

- logic clock, vector clock
- time skew: NTP(network time protocol) ((t2-t1)+(t3-t4))/2 

### Muture Exclusive

- ns[i]: P_require
- ns[j]:
	- no need for the resource: P_ack
	- in CS: after done P_ack
	- compare: P_ack

### Election

- ring
	- ns[i]: P_propose(curring id), when id is equal, P_victory
	- ns[j]:
		- smaller/equal: P_ack
		- bigger: P_propose

- broadcast P_election
	- receive P_response, aggregate to P_response

### Transaction

### Replica/ Consistency

- types
	- read consistency
	- sequence consistency
	- causal consistency
	- eventually consistency

- alg:
	- ps[i]: P_propose, until get all ack
	- ack only when bigger

### Distributed Hash Tables

- key space  (consistent?)
- node space (succ(h(k)), consistent?)
- query      (index-table(2^m), finger-table, etc.)

### Load balance

- alg
	- round-robin
	- least busy
	- ip/id hash
- session persistence
- node change(+/-)