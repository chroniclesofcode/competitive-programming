class H2O {
public:
    std::mutex mtx;
    std::condition_variable cv;
    int ct = 0;

    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [&]() { return ct < 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ct++;
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck, [&]() { return ct == 2; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ct = 0;
        cv.notify_all();
    }
};
