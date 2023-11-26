#include <iostream>
#include <set>

template <typename T>
class SetOperations {
private:
    std::set<T> elements;

public:
    // ��������� �������� �� �������
    void addElement(const T& element) {
        elements.insert(element);
    }

    // ��'������� ������
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

    // ������� ������
    SetOperations<T> intersectSets(const SetOperations<T>& other) const {
        SetOperations<T> result;
        for (const T& element : elements) {
            if (other.containsElement(element)) {
                result.addElement(element);
            }
        }
        return result;
    }

    // г����� ������
    SetOperations<T> differenceSets(const SetOperations<T>& other) const {
        SetOperations<T> result;
        for (const T& element : elements) {
            if (!other.containsElement(element)) {
                result.addElement(element);
            }
        }
        return result;
    }

    // ��������� ������
    bool isEqual(const SetOperations<T>& other) const {
        return elements == other.elements;
    }

    // �������� �� ������� ������ ������ �������
    bool containsElement(const T& element) const {
        return elements.find(element) != elements.end();
    }

    // ��������� �������
    void printSet() const {
        std::cout << "Set: { ";
        for (const T& element : elements) {
            std::cout << element << " ";
        }
        std::cout << "}\n";
    }
};

int main() {
    // ������� ������������ ����� ��� ������
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
