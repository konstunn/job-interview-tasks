
#include <iostream>
#include <string>
#include <cstdlib>
#include <stack>
#include <vector>

template <class T>
class vector2d : public std::vector < std::vector <T> > 
{
	public:

	vector2d (const int M, const int N, const T & val) : 
		std::vector < std::vector <T> > (N, std::vector <T> (M, val)) {}	
};

void breadth_first_search (const vector2d <bool> & map, 
 vector2d <int> & label, int & current_label, 
 const int i, const int j)
{
	const int N = map.size();
	const int M = map.begin()->size();

	/* Label element with incremented value,
	   cause new connected component is found.
	   Then push elem into stack. */
	label[i][j] = ++ current_label;		
	std::stack < std::pair <int,int> > stack;
	stack.push (std::make_pair (i,j));	

	while (! stack.empty())
	{
		const std::pair <int,int> indexes = stack.top();	
		stack.pop();			

		// look around in four directions
		for (int direction = 0; direction < 4; ++ direction)
		{
			const int dx[] = {1, 0, -1, 0};
			const int dy[] = {0, -1, 0, 1};

			// calc indexes
			int ii = indexes.first  + dy [direction];
			int jj = indexes.second + dx [direction];

			// check if indexes are in bounds
			// and if foregnd and not labeled elem found
			if (ii < N && ii >= 0 &&	
				jj < M && jj >= 0 &&	
				map[ii][jj] && ! label[ii][jj]) 
			{	
				// label it with current label
				// and push it into stack		
				label[ii][jj] = current_label;			
				stack.push (std::make_pair (ii,jj));	
			}
		}
	}
}

int count_connected_components 
(const vector2d <bool> & map, vector2d <int> & label) 
{
    const int N = map.size();
    const int M = map.begin()->size();

    int current_label = 0;
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < M; ++j)
        {
			// if elem is foregnd and not labeled
            if (map[i][j] && ! label[i][j]) 
            {   
				breadth_first_search (map, label, current_label, i, j);
			}
        }
    }
    return current_label;
}

int main()
{    
    std::string str;

    std::getline (std::cin, str, ' ');
	const int N = std::stoi (str);

    std::getline (std::cin, str);
	const int M = std::stoi (str); 

    vector2d <bool> map (M, N, false); 

    vector2d <int> labels (M, N, 0); 

    for (int i = 0; i < N; ++i) 
    {
		std::getline (std::cin, str);
        for (int j = 0; j < M; ++j) 
        {
			if ('*' == str[j])
				map[i][j] = true;
        }
    }    

    std::cout << count_connected_components (map, labels) << std::endl;

    return 0;
}
