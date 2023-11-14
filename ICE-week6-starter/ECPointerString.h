#ifndef EC_STRING_PTR
#define EC_STRING_PTR

#include <string>

class ECStringPtr
{
public:
	ECStringPtr();
	ECStringPtr(const std::string &strInit);
	ECStringPtr(const ECStringPtr &rhs);
	ECStringPtr(ECStringPtr &&rhs);
	~ECStringPtr();
	
	ECStringPtr &operator=(const ECStringPtr &rhs);
	std::string GetString() const;
	void SetString(const std::string &strToSet);
	const std::string *GetPtr() const;

        // Skip for the first pass. Create a string by duplicating itself, e.g. if this string is "abc", 
        // the new string is "abcabc"
        ECStringPtr Duplicate() const;
	
private:
  std::string *ptr;
};

#endif
