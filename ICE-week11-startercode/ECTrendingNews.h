#ifndef EC_TRANDING_NEWS_H
#define EC_TRANDING_NEWS_H

#include <vector>
#include <algorithm>

// Subscriber interface. DON'T CHANGE THIS
class ECSubscriber
{
public:
	virtual ~ECSubscriber() {}
    virtual void Update() = 0;
    virtual int ContractCost() const = 0;
};


// This is the subject
class ECTrendingNews
{
public:
	ECTrendingNews() : rev(0) {}
	~ECTrendingNews() {}
	// add a subscriber
	void Subscribe(ECSubscriber *pSub){
		listObs.push_back(pSub);
		ReceivePayment(pSub -> ContractCost());
	}
	// remove a subscriber
	void UnSubscribe(ECSubscriber *pSub){
		listObs.erase(std::remove(listObs.begin(), listObs.end(), pSub), listObs.end());
	}
	// Notify news is available for view
	void Notify(){
		for (auto x : listObs){
			x -> Update();
		}
	}
	// receive payment (assume in whole dollar)
	void ReceivePayment(int amount)
	{
		rev += amount;
	}
	// Get total revenue received
	int GetTotRevenue() const {return rev;}
	
private:
	int rev;
	std::vector<ECSubscriber *> listObs;
};


// pay-per click subscriber
class ECPayPerClickSubscriber : public ECSubscriber
{
public:
	ECPayPerClickSubscriber(ECTrendingNews &tnIn) : tn(tnIn) {}
	~ ECPayPerClickSubscriber() {}
	virtual void Update() 
	{
		tn.ReceivePayment(1);
	}
	virtual int ContractCost() const {
		return 0;
	}
private:
	ECTrendingNews &tn;
};

// Contract subscriber
class ECContractSubscriber : public ECSubscriber
{
public:
	ECContractSubscriber(ECTrendingNews &tnIn) : tn(tnIn) {}
	~ECContractSubscriber() {}
	virtual void Update() 
	{
	}
	virtual int ContractCost() const 
	{
		return 100;
	}
private:
	ECTrendingNews &tn;
};

#endif
