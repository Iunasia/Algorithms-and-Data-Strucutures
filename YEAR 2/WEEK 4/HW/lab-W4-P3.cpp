#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Browser {
    private:
        stack<string> backS;
        stack<string> forwardS;
        string current;

    public:

        Browser(string home){
            current = home;
        }

        void go(string URL){
            backS.push(current);
            current = URL;
            while(!forwardS.empty()){
                forwardS.pop();
            
            }

            printStatus();
        }
    
        void back(){
            if(backS.empty()){
                return;
            }
            forwardS.push(current);
            current = backS.top();
            backS.pop();
            printStatus();
        }

        void forward(){
            if(forwardS.empty()){
                return;
            }
            backS.push(current);
            current = forwardS.top();
            forwardS.pop();
            printStatus();
        }

        void printStatus(){
            cout <<"\n Now At: " << current << endl;
            stack<string> t = backS;
            if(t.empty()) cout <<"empty";
            while(!t.empty()){
                cout << t.top() << " ";
                t.pop();
            }
            cout << endl;
            cout << "forward stack: ";
            t = forwardS;
            if(t.empty()) cout << "empty";
            while(!t.empty()){
                cout << t.top() << " ";
                t.pop();
            }

            cout << endl;
            
        }
};

int main(){

    Browser browser("youtube.com");

    browser.go("X.com");
    browser.go("github.com");
    browser.go("Chatgpt.com");

    browser.back();
    browser.back();
    browser.forward();
    browser.go("Facebook.com");
    return 0;
}