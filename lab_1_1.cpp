#include <iostream>
using namespace std;

class Product
{
	int price;
public:
	void setPrice(int pr) { price = pr; }
	int getPrice() const { return price; }
	
};


class IValidation
{
public:
	virtual bool Check(int price) const = 0;
	
};


class CustomerServiceValidation : public IValidation {
	bool isCustomerService = false;
public:
	void setCustomerService(bool cs) { isCustomerService = cs; }

	bool Check(int price) const override {
		if (isCustomerService) {
			return price > 10000;
		}
		else return price > 0;
	}
};

int main() {
	Product product;
	product.setPrice(150000);

	CustomerServiceValidation validator;
	validator.setCustomerService(true);
	if (validator.Check(product.getPrice())) {
		cout << "Product is valid" << endl;
	}
	else cout << "Product is invalid";
}
