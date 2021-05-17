#include <iostream>
#include <string>
#include <memory>
#include <unordered_set>
#include <utility>
#include <vector>


/*
 *
 * discord paramters 
 * social stickyness: 1 = strangers, 4 = e-dating server
 * growth rate		: 1 = shrinking, 4 = expanding rapidly
 * moderation:		: 1 = complete anarchy, 4 = rules server
 * focus			: 1 = anarchy,  4 = hobby server
 * voice focus:		: 1 = just voice,	4 = just text
 *
 * SGMFV  
 * 33332 = ideal
 * 22212 = current
 * 11114 = worst
 *
 */
struct Paramter
{
	const int range;
	const std::string name;
	const std::vector<std::string> desc;
};

struct FRating
{
	const std::pair<int, int> ratings;
	const std::pair<std::shared_ptr<Paramter>, 
				    std::shared_ptr<Paramter>> params;
};

namespace std
{
	template<> struct hash<FRating>
	{
		std::size_t operator()(FRating const& s) const noexcept 
		{
			const auto h1 = std::hash<std::string>{}(s.params.first->name);
			const auto h2 = std::hash<std::string>{}(s.params.second->name);
			return h1 ^ (h2 << 1);
		}
	};
}

class seer 
{
	std::vector<std::shared_ptr<Paramter>> res;
	std::unordered_set<FRating> feasible;

};

auto main (void) -> int
{	
}

