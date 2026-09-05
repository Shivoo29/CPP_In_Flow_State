// ============================================================
// A LOG CLASS -- enums + encapsulation working together
// ------------------------------------------------------------
// Shows why you make data private: m_LogLevel can only be changed
// through Setlevel(), which takes a Level. Nobody can shove an
// arbitrary int in and put the object into a nonsense state.
// The nested enum also demonstrates severity filtering: pick a level,
// and anything less severe is silently dropped.
// ============================================================

#include <iostream>
using namespace std;

class Log{
    public:
    // Enum nested inside the class, so it is referred to from outside
    // as Log::LevelError. Keeps the name from polluting everything else.
    enum Level{
        LevelError =0 , LevelWarning, LevelInfo  // 0, 1, 2
        // Order matters: the >= comparisons below rely on
        // Error < Warning < Info, i.e. lower number = more severe.
    };

    private:
    Level m_LogLevel = LevelInfo; // it is good practice to have a m_ prefix for member variables to avoid confusion with local variables
                                  // Default: show everything.

    public:
    void Setlevel(Level level){
        m_LogLevel = level;
    }
    // Each of these prints only if the current level is verbose enough.
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
        if(m_LogLevel >= LevelError){   // always true -- errors never hidden
            cout << "[Error]: " << message << endl;
        }
    }
};

int main(){
    Log log;
    log.Setlevel(Log::LevelError);   // most restrictive: errors only
    log.Warn("This is a warning");   // 0 >= 1 is false -> not printed
    log.Error("This is an error");   // 0 >= 0 is true  -> printed
}
