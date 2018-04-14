modela_first = 0.1
modelb_first = 0.2
modelc_first = 0.3
matrix_model <- matrix(1:1, nrow = 3, ncol = 3)
for(row_num in 1:3){
  matrix_model[row_num, ] <- c(modela_first^row_num, modelb_first^row_num, modelc_first^row_num)
}