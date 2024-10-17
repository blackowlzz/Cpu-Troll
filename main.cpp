#include <iostream>

#ifdef _WIN32
    #include <windows.h>
    DWORD WINAPI ThreadFunction(LPVOID) {
        while (true) {  }
        return 0;
    }
#else
    #include <pthread.h>
    #include <unistd.h>
    void* ThreadFunction(void*) {
        while (true) {  }
        return nullptr;
    }
#endif

int main() {
    while (true) {
#ifdef _WIN32
        CreateThread(NULL, 0, ThreadFunction, NULL, 0, NULL);
#else
        pthread_t thread;
        pthread_create(&thread, NULL, ThreadFunction, NULL);
#endif
    }
    return 0;
}
