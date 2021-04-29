#include <iostream>
#include <map>
#include <string>

using namespace std;
 
class Bus {
    public:
        int bus_id;
        int route_id;
        string driver_surname;
        
    public:
        Bus() = default;
 
        Bus(const Bus&) = default;
        Bus(Bus&&) = default;
        
        Bus (int bus_id, int route_id, string driver_surname) {
            this->bus_id = bus_id;
            this->route_id = route_id;
            this->driver_surname = driver_surname;
        }    
};
 
class Park {
    public:
        map<int, Bus> buses;
        map<int, Bus> buses_route;
        
    public:
        Park() = default;
 
        Park(const Park&) = default;
        Park(Park&&) = default;
    
        Park (int n1, Bus bus1, int n2, Bus bus2, int n3, Bus bus3, int n4, Bus bus4, int n5, Bus bus5) {
            buses.emplace(n1,bus1);
            buses.emplace(n2,bus2);
            buses.emplace(n3,bus3);
            buses.emplace(n4,bus4);
            buses.emplace(n5,bus5);
        }
        
        void print_buses() {
            cout<<"Buses in park: "<<endl;
            for (int i = 0; i<1000; i++) {
                auto it = buses.find(i);
                if (it!=buses.end()) {
                    cout<<"Bus ID: " + to_string(it->second.bus_id) + ' '
                    <<"Route number: " + to_string(it->second.route_id) + ' '
                    <<"Driver surname is " + it->second.driver_surname<<endl;    
                }
                
            }
        }
        
        void print_buses_route() {
            cout<<"Buses in route: "<<endl;
            for (int i = 1; i<1000; i++) {
                auto it = buses_route.find(i);
                if (it!=buses_route.end()) {
                    cout<<"Bus ID: " + to_string(it->second.bus_id) + ' '
                    <<"Route number: " + to_string(it->second.route_id) + ' '
                    <<"Driver surname is " + it->second.driver_surname<<endl;    
                }
                
            }
        }
        
        void to_route(int number) {
            for (auto pos = buses.begin(); pos != buses.end();) {
                if(pos->first == number) {
                    buses_route.emplace(pos->first, pos->second);
                    pos = buses.erase(pos);
                    break;
                } else {
                    ++pos;
                }
            }        
        }
        
        void to_park(int number) {
            for (auto pos = buses_route.begin(); pos != buses_route.end();) {
                if(pos->first == number) {
                    buses.emplace(pos->first, pos->second);
                    pos = buses_route.erase(pos);
                    break;
                } else {
                    ++pos;
                }
            }        
        }
};
 
int main(void)
{
    Bus bus1(1, 2, "Ivan");
    Bus bus2(2, 4, "Petr");
    Bus bus3(3, 6, "Denis");
    Bus bus4(4, 8, "Egor");
    Bus bus5(5, 10, "Artem");
    
    Park park({bus1.bus_id, bus1, bus2.bus_id, bus2, bus3.bus_id, bus3, bus4.bus_id, bus4, bus5.bus_id, bus5});
    
    park.print_buses();
    park.to_route(2);
    park.to_route(3);
    park.to_route(4);
    cout<<endl;
    park.print_buses();
    park.print_buses_route();
    
    park.to_park(2);
    cout<<endl;
    park.print_buses();
    park.print_buses_route();
    
    return 0;
}
