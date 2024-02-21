class FizzBuzz {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    int ct = 1;
    int end = 0;
public:
    FizzBuzz(int n) {
        this->n = n;
    }

    void increment() {
        ct++;
        if (ct == n+1) end = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while (1) {
            {
                unique_lock<mutex> lck(mtx);
                cv.wait(lck, [&]() {
                    return (ct%3==0 && ct%5!=0) || end;
                });
                if (end) return;
                printFizz();
                increment();
            }
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while (1) {
            {
                unique_lock<mutex> lck(mtx);
                cv.wait(lck, [&]() {
                    return (ct%3!=0 && ct%5==0) || end;
                });
                if (end) return;
                printBuzz();
                increment();
            }
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while (1) {
            {
                unique_lock<mutex> lck(mtx);
                cv.wait(lck, [&]() {
                    return (ct%3==0 && ct%5==0) || end;
                });
                if (end) return;
                printFizzBuzz();
                increment();
            }
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while (1) {
            {
                unique_lock<mutex> lck(mtx);
                cv.wait(lck, [&]() {
                    return (ct%3!=0 && ct%5!=0) || end;
                });
                if (end) return;
                printNumber(ct);
                increment();
            }
            cv.notify_all();
        }
    }
};
