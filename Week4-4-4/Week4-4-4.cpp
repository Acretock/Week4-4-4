#include <iostream>
#include <exception>
#include <ctime>
#include <string>
using namespace std;

string AskTimeServerTest() {
    // ��� ������������ ������������ ���� ���, ����������� ��������� ��������� ���� ������:
       // ���������� ������� ���������� ��������
       // ������ ���������� system_error
       // ������ ������� ���������� � ����������.
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
    // ��� ������������ ������������ ���� ���, ����������� ��������� ��������� ���� ������:
       // ���������� ������� ���������� ��������
       // ������ ���������� system_error
       // ������ ������� ���������� � ����������.
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
            // ���� AskTimeServer() ������� ��������, �������� ��� � last_fetched_time � �������
            // ���� AskTimeServer() ������� ���������� system_error, ������� ������� �������� ���� last_fetched_time
            // ���� AskTimeServer() ������� ������ ����������, ���������� ��� ������.
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
    // ����� ���������� ������� AskTimeServer, ���������, ��� ��� ��� �������� ���������
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    }
    catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
