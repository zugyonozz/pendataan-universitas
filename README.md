/akademik-system
│
├── /bin                      # <-- Hasil build/output executable
│   └── akademik             # atau akademik.exe di Windows
│
├── /include                 # Header eksternal (library)
│   └── sqlite3.h
│
├── /lib                     # Static libraries
│   └── libsqlite3.a
│
├── /src                     # Source code program
│   ├── main.cpp
│   ├── config.h
│   ├── database.cpp
│   ├── /modules
│   │   ├── mahasiswa.cpp
│   │   └── jurusan.cpp
│   ├── /ui
│   └── /utils
│
├── /data                    # Database file, backup, dsb
│   └── database.db
│
├── /docs                    # Dokumentasi proyek
│   └── README.md
│
├── init.sql                 # SQL schema awal
└── Makefile                 # Build automation
