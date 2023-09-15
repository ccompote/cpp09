#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cctype>

# define MICROSECOND 100000

class Pmerge
{
	private:

		std::vector<int> _input;
		int _subarrsize;
		std::vector<int> _sortedVector;
		std::deque<int> _sortedDeque;

	public:

		Pmerge(void);
		Pmerge(std::vector<int> input);
		Pmerge(const Pmerge &copy);
		Pmerge &operator=(const Pmerge &copy);
		~Pmerge(void);

		void result(void);
		void insertionSortD(size_t left, size_t right);
		void mergeInsertionSortD(size_t left, size_t right);
		void mergeD(size_t left, size_t middle, size_t right);
		void mergeInsertionSortV(int left, int right);
		void insertionSortV(int left, int right);
		void mergeV(int left, int middle, int right);
};