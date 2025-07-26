class Teacher : public Person {
public:
    void display() override { // Override base class function
        cout << "I am a Teacher" << endl;
    }
