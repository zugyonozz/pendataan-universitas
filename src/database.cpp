#include "database.h"
#include <iostream>

sqlite3* bukaDatabase(const std::string& path) {
    sqlite3* db = nullptr;
    if (sqlite3_open(path.c_str(), &db) != SQLITE_OK) {
        std::cerr << "Gagal membuka database: " << sqlite3_errmsg(db) << std::endl;
        return nullptr;
    }
    return db;
}

bool initDatabase(sqlite3* db) {
    const char* sql = R"sql(
        CREATE TABLE IF NOT EXISTS mahasiswa (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            nama TEXT NOT NULL,
            nim TEXT NOT NULL,
            jurusan TEXT NOT NULL
        );
    )sql";

    char* errMsg = nullptr;
    if (sqlite3_exec(db, sql, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Gagal inisialisasi tabel: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}

bool tambahMahasiswa(sqlite3* db, const std::string& nama, const std::string& nim, const std::string& jurusan) {
    const char* sql = "INSERT INTO mahasiswa (nama, nim, jurusan) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt, 1, nama.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, nim.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, jurusan.c_str(), -1, SQLITE_TRANSIENT);

    bool success = (sqlite3_step(stmt) == SQLITE_DONE);
    sqlite3_finalize(stmt);
    return success;
}

std::vector<Mahasiswa> ambilSemuaMahasiswa(sqlite3* db) {
    std::vector<Mahasiswa> hasil;
    const char* sql = "SELECT id, nama, nim, jurusan FROM mahasiswa;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) != SQLITE_OK)
        return hasil;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        Mahasiswa m;
        m.id = sqlite3_column_int(stmt, 0);
        m.nama = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        m.nim = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        m.jurusan = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        hasil.push_back(m);
    }

    sqlite3_finalize(stmt);
    return hasil;
}
