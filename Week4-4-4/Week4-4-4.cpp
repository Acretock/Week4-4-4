#include <iostream>
#include <exception>
#include <ctime>
#include <string>
using namespace std;

string AskTimeServerTest() {
    // ƒл€ тестировани€ повставл€йте сюда код, реализующий различное поведение этой функии:
       // нормальный возврат строкового значени€
       // выброс исключени€ system_error
       // выброс другого исключени€ с сообщением.
    int a;
    cin >> a;
    if (a == 1)
        return "09:11:42";
    if (a == 2) {
        throw system_error(error_code()); 
    }
    if (a == 3) {
        exception e("this is wrong");
        throw (e);
    }
     
}

string AskTimeServer() {
    // ƒл€ тестировани€ повставл€йте сюда код, реализующий различное поведение этой функии:
       // нормальный возврат строкового значени€
       // выброс исключени€ system_error
       // выброс другого исключени€ с сообщением.
    int a;
    cin >> a;
    if (a == 1)
        return "09:11:42";
    if (a == 2) {
        throw system_error(error_code());
    }
    if (a == 3) {
        exception e("this is wrong");
        throw (e);
    }

}

class TimeServer {
public:
    string GetCurrentTime() {
            // если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            // если AskTimeServer() бросила исключение system_error, верните текущее значение пол€ last_fetched_time
            // если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        try {
            last_fetched_time = AskTimeServer();    // if no exeption was thrown
            return last_fetched_time;
        }
        catch (system_error&e) {                    
            return last_fetched_time;               //sys error
        }
        catch (exception& e) {                      // any other exeption 
            throw (e);
        }
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // ћен€€ реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
