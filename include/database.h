#pragma once
#include <sqlite3.h>
#include <string>
#include <vector>

struct Mahasiswa {
    int id;
    std::string nama;
    std::string nim;
    std::string jurusan;
};

sqlite3* bukaDatabase(const std::string& path);
bool initDatabase(sqlite3* db);
bool tambahMahasiswa(sqlite3* db, const std::string& nama, const std::string& nim, const std::string& jurusan);
std::vector<Mahasiswa> ambilSemuaMahasiswa(sqlite3* db);
