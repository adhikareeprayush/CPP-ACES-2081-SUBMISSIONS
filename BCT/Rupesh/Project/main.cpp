// Simplified CLI Todo List with Undo (Single-Level Undo)

#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Task {
    int id;
    string text;
    bool done;
};
class TodoList {
    vector<Task> tasks;
    vector<Task> backup;
    int lastAction; // 1 = Add, 2 = Done, 3 = Delete, 0 = None
    int lastActionId;

public:
    TodoList() : lastAction(0), lastActionId(-1) {}

    void addTask(const string& txt) {
        backupTasks();
        Task t = {tasks.empty() ? 1 : tasks.back().id + 1, txt, false};
        tasks.push_back(t);
        lastAction = 1;
        lastActionId = t.id;
        cout << "Task added!\n";
    }

    void listTasks() {
        if (tasks.empty()) {
            cout << "No tasks yet.\n";
            return;
        }
        for (auto& t : tasks) {
            cout << (t.done ? "[✔] " : "[ ] ") << t.id << ". " << t.text << endl;
        }
    }

    void markDone(int id) {
        for (auto& t : tasks) {
            if (t.id == id) {
                backupTasks();
                t.done = true;
                lastAction = 2;
                lastActionId = id;
                cout << "Task marked as done!\n";
                return;
            }
        }
        cout << "Task not found.\n";
    }

    void deleteTask(int id) {
        for (size_t i = 0; i < tasks.size(); ++i) {
            if (tasks[i].id == id) {
                backupTasks();
                tasks.erase(tasks.begin() + i);
                lastAction = 3;
                lastActionId = id;
                cout << "Task deleted!\n";
                return;
            }
        }
        cout << "Task not found.\n";
    }

    void undo() {
        if (lastAction == 0) {
            cout << "Nothing to undo.\n";
            return;
        }
        tasks = backup;
        cout << "Last action undone.\n";
        lastAction = 0;
    }

private:
    void backupTasks() {
        backup = tasks;
    }
};

int main() {
    TodoList todo;
    int choice;
    do {
        cout << "\n--- TODO MENU ---\n";
        cout << "1. List tasks\n";
        cout << "2. Add task\n";
        cout << "3. Mark task done\n";
        cout << "4. Delete task\n";
        cout << "5. Undo last action\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            todo.listTasks();
        } else if (choice == 2) {
            string txt;
            cout << "Enter task: ";
            getline(cin, txt);
            todo.addTask(txt);
        } else if (choice == 3) {
            int id;
            cout << "Enter task ID to mark done: ";
            cin >> id;
            todo.markDone(id);
        } else if (choice == 4) {
            int id;
            cout << "Enter task ID to delete: ";
            cin >> id;
            todo.deleteTask(id);
        } else if (choice == 5) {
            todo.undo();
        } else if (choice != 0) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    cout << "Goodbye!\n";
    return 0;
}
