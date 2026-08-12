#include <iostream>
using namespace std;

class Log{
    public:
    enum Level{
        LevelError =0 , LevelWarning, LevelInfo
    };

    private:
    Level m_LogLevel = LevelInfo; // it is good practice to have a m_ prefix for member variables to avoid confusion with local variables

    public:
    void Setlevel(Level level){
        m_LogLevel = level;
    }
    void Warn(const char* message){
        if(m_LogLevel >= LevelWarning){
            cout << "[Warning]: " << message << endl;
        }
    }
    void Info(const char* message){
        if(m_LogLevel >= LevelInfo){
            cout << "[Info]: " << message << endl;
        }
    }
    void Error(const char* message){
        if(m_LogLevel >= LevelError){
            cout << "[Error]: " << message << endl;
        }
    }
};

int main(){
    Log log;
    log.Setlevel(Log::LevelError);
    log.Warn("This is a warning");
    log.Error("This is an error");
}