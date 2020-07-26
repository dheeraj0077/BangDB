The test files for leveldb, bdb and bangdb for various performance test cases.

The executable can be compiled by using following;

> bash build.sh

to run the test do following;

bash runapp.sh <bangdb/bdb/leveldb> <num_threads> <num_items> <put/get/all>

hence to run leveldb test with 2 threads to put 1M key val 

> bash runapp.sh leveldb 2 1000000 put

for get

> bash runapp.sh leveldb 2 1000000 get

etc...

The cache sizes for bdb and leveldb can be edited in their respective bench files whereas all config for bangdb is in bangdb.config file.
