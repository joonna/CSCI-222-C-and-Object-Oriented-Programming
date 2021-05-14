#include "FileIO.h"

FileIO::FileIO(string src) {
    fp = new ifstream(src);
}
ifstream *FileIO::getFP() const {
    return fp;
}
FileIO::~FileIO() {
    delete fp;
}