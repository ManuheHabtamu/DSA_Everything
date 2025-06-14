/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mapper;
        for (Employee* e: employees){
            mapper[e->id] = e;
        }
        return getImp(mapper,id);
    }
private:
    int getImp(unordered_map<int, Employee*> &mapper, int id) {
        Employee* e = mapper[id];
        int imp = e->importance;
        for(int subid: e->subordinates){
            imp+=getImp(mapper,subid);
            }
        return imp;
        }
};