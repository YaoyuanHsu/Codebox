first <- -1
last <- 3
loop <- 0.1
num <- (last - first) %/% loop + 1
x <- seq(first, last, loop)
y <- vector("numeric", num)
for(n in c(1 : num))
  if(x[n] < 0){
    y[n] <- x[n]^2+2*x[n]+3
  }else if((0 <= x[n]) & (x[n] < 2)){
    y[n] <- x[n]+3
  }else{
    y[n] <- x[n]^2+4*x[n]-7
  }
#??????4