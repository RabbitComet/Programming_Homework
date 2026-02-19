#include <iostream>

int main()
{
    int size;
    
    std::cout<<"Size: ";
    
    std::cin>>size;
    
    int** matrix = new int*[size];
    
    for(int i = 0 ; i < size; i++){
        *(matrix+i) = new int[size];
        for(int j = 0; j<size;j++){
            
            std::cout<<"Number: ";
            std::cin>>*(*(matrix+i)+j);
        }
        
    }
    
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j<size;j++){
            std::cout<<*(*(matrix+i)+j)<<" ";
        }
        std::cout<<std::endl;
        
    }
    
    int* row_sums = new int[size];
    int* col_sums = new int[size];
    int matrix_sum = 0;
    int main_diagonal = 0;
    int secondary_diagonal = 0;
    int max = **matrix;
    int min = **matrix;
    
    for(int i = 0; i <size; i++){
        
        for(int j = 0; j < size; j++){
            int curr_num = *(*(matrix+i)+j); 
            
            matrix_sum += curr_num;
            
            if(i == j){
                main_diagonal += curr_num ;
            }
            
            if( i + j == size - 1 ){
                secondary_diagonal += curr_num;
            }
            
            *(row_sums + i) += curr_num;
            *(col_sums + j) += curr_num;
            
            if(curr_num > max){
                max = curr_num;
            }
            
            if(curr_num < min){
                min = curr_num;
            }
            
        }
        
    }
    
    for(int i = 0; i < size; i++){
        std::cout<<"Sum of row "<<i<<": "<<*(row_sums+i)<<std::endl;
    }
    
    for(int i = 0; i < size; i++){
        std::cout<<"Sum of column "<<i<<": "<<*(col_sums+i)<<std::endl;
    }
    
    std::cout<<"Sum of the entire Matrix: "<<matrix_sum<<std::endl;
    
    std::cout<<"Sum of the main diagonal: "<<main_diagonal<<std::endl;
    
    std::cout<<"Sum of the secondary diagonal: "<<secondary_diagonal<<std::endl;
    
    std::cout<<"Maximum element: " << max <<std::endl;
    
    std::cout<<"Minimum element: " << min <<std::endl;
    
    for(int i = 0; i<size; i++){
        
        delete[] *(matrix+i);
    }
    
    delete[] row_sums;
    delete[] col_sums;
    delete[] matrix;

    return 0;
}