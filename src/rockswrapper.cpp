#include "rockswrapper.h"

namespace RocksWrapper {

void connect()
{
    rocksdb::DB* db;
    rocksdb::Options options;
    std::string value;
    std::string value2;

    options.create_if_missing = true;
    rocksdb::Status status = rocksdb::DB::Open(options, "/tmp/testdb", &db);
    
    if (status.ok()) {
        puts("Connected to RocksDB");
    } else {
        fprintf(stderr, "%s\n", status.ToString().c_str());
    }
    
    // Slice type should be used in place of std::string for key-value
    rocksdb::Slice key = "foo";
    std::string value1 = "bar";
    
    // Modify/query the database
    status = db->Put(rocksdb::WriteOptions(), key, value1);
    assert(status.ok());

    status = db->Get(rocksdb::ReadOptions(), key, &value2);
    assert(status.ok() && value1 == value2);
    
    status = db->Delete(rocksdb::WriteOptions(), key);
    assert(status.ok());
    
    status = db->Get(rocksdb::ReadOptions(), key, &value2);
    assert(status.IsNotFound());

    delete db;
}

} // RocksWrapper

int main()
{
    RocksWrapper::connect();
    return 0;
}
