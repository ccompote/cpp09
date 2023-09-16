#include "PmergeMe.hpp"

Pmerge::Pmerge(void) {}

Pmerge::~Pmerge(void) {}

Pmerge::Pmerge(std::vector<int> input)
{
	_subarrsize = 2; // Adjust this as needed
	_input = input;
} 

Pmerge::Pmerge(const Pmerge &copy)
{
	*this = copy;
}

Pmerge &Pmerge::operator=(const Pmerge &copy)
{
	if (this == &copy)
		return (*this);
	return (*this);
}

void Pmerge::insertionSortV(int left, int right) 
{
    for (int i = left + 1; i <= right; i++)
	{
        int key = _sortedVector[i];
        int j = i - 1;

        while (j >= left && _sortedVector[j] > key) 
		{
            _sortedVector[j + 1] = _sortedVector[j]; 
            --j;
        }

        _sortedVector[j + 1] = key;
    }
}

void Pmerge::mergeV(int left, int middle, int right) 
{
    int n1 = middle - left + 1; 
    int n2 = right - middle;

    std::vector<int> leftArray(n1);
    std::vector<int> rightArray(n2);

    for (int i = 0; i < n1; i++)
        leftArray[i] = _sortedVector[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = _sortedVector[middle + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
	{
        if (leftArray[i] <= rightArray[j]) 
		{
            _sortedVector[k] = leftArray[i];
            ++i;
        } 
		else 
		{
            _sortedVector[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) 
	{
        _sortedVector[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < n2) 
	{
        _sortedVector[k] = rightArray[j];
        ++j;
        ++k;
    }
}

void Pmerge::mergeInsertionSortV(int left, int right) 
{
    if (right - left + 1 <= _subarrsize)
        insertionSortV(left, right);
    else 
	{
        int middle = left + (right - left) / 2; 
        mergeInsertionSortV(left, middle); 
        mergeInsertionSortV(middle + 1, right);
        mergeV(left, middle, right); 
    }
}

void Pmerge::insertionSortD(size_t left, size_t right) 
{
    for (size_t i = left + 1; i <= right; i++) 
	{
		int key = _sortedDeque[i];
		size_t j = i;

		while (j > left && _sortedDeque[j - 1] > key) 
		{
			_sortedDeque[j] = _sortedDeque[j - 1];
			--j;
		}
		_sortedDeque[j] = key;
    }
}

void Pmerge::mergeD(size_t left, size_t middle, size_t right) 
{
	size_t n1 = middle - left + 1;
	size_t n2 = right - middle;

	std::deque<int> leftDeque(n1);
    std::deque<int> rightDeque(n2);

    for (size_t i = 0; i < n1; i++)
        leftDeque[i] = _sortedDeque[left + i];
    for (size_t j = 0; j < n2; j++)
        rightDeque[j] = _sortedDeque[middle + 1 + j];
	size_t i = 0, j = 0, k = left;

	while (i < n1 && j < n2) 
	{
		if (leftDeque[i] <= rightDeque[j]) 
		{
			_sortedDeque[k] = leftDeque[i];
			++i;
		} 
		else 
		{
			_sortedDeque[k] = rightDeque[j];
			++j;
		}
		++k;
	}

	while (i < n1)
	 {
		_sortedDeque[k] = leftDeque[i];
		++i;
		++k;
	}

	while (j < n2) 
	{
		_sortedDeque[k] = rightDeque[j];
		++j;
		++k;
	}
}

void Pmerge::mergeInsertionSortD(size_t left, size_t right) 
{
    size_t n = right - left + 1;

	if (n <= static_cast<size_t>(_subarrsize)) 
		insertionSortD(left, right);
	else 
	{
		size_t middle = left + (right - left) / 2;
		mergeInsertionSortD(left, middle);
		mergeInsertionSortD(middle + 1, right);
		mergeD(left, middle, right);
	}
}

void Pmerge::result(void)
{
    std::cout << "Before: ";
    for (size_t i = 0; i < _input.size(); i++) 
        std::cout << _input[i] << ' ';
    std::cout << std::endl;

	for (size_t i = 0; i < _input.size(); i++) 
        _sortedVector.push_back(_input[i]);
	clock_t startTime = clock();
    mergeInsertionSortV(0, _input.size() - 1);
	clock_t endTime = clock();
	double elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * MICROSECOND;
    std::cout << "After (Vector): ";
    for (size_t i = 0; i < _sortedVector.size(); i++)
        std::cout << _sortedVector[i] << ' ';
		std::cout << std::endl;
	std::cout << "Time to process a range of " << _input.size() << " elements with std::vector: " << elapsedTime  << std::endl;
	
	_sortedDeque.assign(_input.begin(), _input.end());
	startTime = clock();
	mergeInsertionSortD(0, _sortedDeque.size() - 1);
	endTime = clock();
	elapsedTime = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * MICROSECOND;
	// std::cout << "After (Deque): ";
    // for (size_t i = 0; i < _sortedDeque.size(); i++) {
    //     std::cout << _sortedDeque[i] << ' ';
    // }
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _input.size() << " elements with std::deque: " << elapsedTime << std::endl;
}