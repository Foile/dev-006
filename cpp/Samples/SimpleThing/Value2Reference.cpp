#include <string>
#include <list>
#include <map>
using namespace ::std;

class Customer
{
private:
	string Name;
    Customer(string Name) : Name(Name) {}
	static map<string,Customer*> Instaces;
	void Store()
	{
		Instaces[GetName()] = this;
	}
public:	
	string GetName() {return Name;}
	static Customer *Create(string Name)
	{
		return Instaces[Name];
	}
	static void LoadCustomers()
	{
		(new Customer("Ivanov"))->Store();
		(new Customer("Petrov"))->Store();
		(new Customer("Sidorov"))->Store();
	}

};

class Order
{
 Customer *Client;
public:
	Order(string CustomerName) 
	{
		Client = Customer::Create(CustomerName);
	}
	string GetCustomerName()
	{
		return Client->GetName();
	}
};

int NumberOfOrdersFor(list<Order> Orders,string customerName)
{
	int result = 0;
	list<Order>::iterator iter = Orders.begin();
	while(iter != Orders.end())
	{
		if(iter->GetCustomerName() == customerName)
			result++;
	}
	return result;
}