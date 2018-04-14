matrix_start <- 0
matrix_size <- 10
x_matrix <- matrix(list(), (nrow = matrix_size), (ncol = matrix_size))
for(row_base in 1 : matrix_size){
    x_matrix[row_base, ] <- seq(matrix_start, (matrix_start + matrix_size - 1), 1) %% matrix_size
    matrix_start <- matrix_start + 1
}
#Question3.a & b