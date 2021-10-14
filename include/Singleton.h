#ifndef SDL_CPP_SINGLETON_H
#define SDL_CPP_SINGLETON_H

template <class T>
class TSingleton {

protected:
    static T *singleton;

public:
    virtual ~TSingleton() {

    }

    inline static T* Get() {
        if (!singleton) {
            singleton = new T;
        }

        return singleton;
    }

    static void Del () {
        if (singleton) {
            delete singleton;
            singleton = nullptr;
        }
    }

};

template <class T>
T* TSingleton<T>::singleton = 0;

#endif //SDL_CPP_SINGLETON_H
