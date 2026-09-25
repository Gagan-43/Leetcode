class FooBar {
private:
    int n;

//2420906
//Gagandeep Singh

    mutex mtx;
    condition_variable cv;
    bool fooTurn = true;
//2420906
//Gagandeep Singh

public:
    FooBar(int n) {
        this->n = n;
    }
//2420906
//Gagandeep Singh

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
//2420906
//Gagandeep Singh

            cv.wait(lock, [&]() {
                return fooTurn;
            });
//2420906
//Gagandeep Singh

            printFoo();
//2420906
//Gagandeep Singh

            fooTurn = false;
            cv.notify_all();
        }
    }
//2420906
//Gagandeep Singh

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
//2420906
//Gagandeep Singh

            cv.wait(lock, [&]() {
                return !fooTurn;
            });
//2420906
//Gagandeep Singh

            printBar();

            fooTurn = true;
            cv.notify_all();
        }
    }
};