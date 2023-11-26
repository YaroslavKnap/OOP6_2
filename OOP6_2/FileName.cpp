#include <iostream>
#include <set>

template <typename T>
class SetOperations {
private:
    std::set<T> elements;

public:
    // Додавання елемента до множини
    void addElement(const T& element) {
        elements.insert(element);
    }

    // Об'єднання множин
    SetOperations<T> unionSets(const SetOperations<T>& other) const {
        SetOperations<T> result;
        for (const T& element : elements) {
            result.addElement(element);
        }
        for (const T& element : other.elements) {
            result.addElement(element);
        }
        return result;
    }

    // Перетин множин
    SetOperations<T> intersectSets(const SetOperations<T>& other) const {
        SetOperations<T> result;
        for (const T& element : elements) {
            if (other.containsElement(element)) {
                result.addElement(element);
            }
        }
        return result;
    }

    // Різниця множин
    SetOperations<T> differenceSets(const SetOperations<T>& other) const {
        SetOperations<T> result;
        for (const T& element : elements) {
            if (!other.containsElement(element)) {
                result.addElement(element);
            }
        }
        return result;
    }

    // Порівняння множин
    bool isEqual(const SetOperations<T>& other) const {
        return elements == other.elements;
    }

    // Перевірка чи множина містить певний елемент
    bool containsElement(const T& element) const {
        return elements.find(element) != elements.end();
    }

    // Виведення множини
    void printSet() const {
        std::cout << "Set: { ";
        for (const T& element : elements) {
            std::cout << element << " ";
        }
        std::cout << "}\n";
    }
};

int main() {
    // Приклад використання класу для множин
    SetOperations<int> set1;
    set1.addElement(1);
    set1.addElement(2);
    set1.addElement(3);

    SetOperations<int> set2;
    set2.addElement(2);
    set2.addElement(3);
    set2.addElement(4);

    SetOperations<int> unionSet = set1.unionSets(set2);
    unionSet.printSet();

    SetOperations<int> intersectSet = set1.intersectSets(set2);
    intersectSet.printSet();

    SetOperations<int> differenceSet = set1.differenceSets(set2);
    differenceSet.printSet();

    bool areEqual = set1.isEqual(set2);
    std::cout << "Sets are equal: " << (areEqual ? "true" : "false") << std::endl;

    return 0;
}
