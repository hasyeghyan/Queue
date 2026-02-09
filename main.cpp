#include "Queue.hpp"

int main() {
    Queue<std::string> q1;
    q1.push("Apple");
    q1.push("Banana");
    q1.push("Cherry");

    std::cout << "Original q1 front: " << q1.front() << "\n";

    Queue<std::string> q2 = q1; 
    std::cout << "Copied q2 front: " << q2.front() << "\n";
    std::cout << "Are they equal? " << (q1 == q2 ? "Yes" : "No") << "\n";

    Queue<std::string> q3 = std::move(q1);

    std::cout << "\n--- After Move ---\n";
    std::cout << "q3 (new owner) front: " << q3.front() << "\n";
    
    if (q1 != q3) {
        std::cout << "q1 and q3 are no longer equal.\n";
    }

    q3.pop();
    if (q3 > q2) {
        std::cout << "q3 is greater than q2\n";
    } else {
        std::cout << "q2 is greater than q3\n";
    }

    const Queue<std::string>& const_q = q3;
    std::cout << "Const front access: " << const_q.front() << "\n"; 
    
    return 0;
}