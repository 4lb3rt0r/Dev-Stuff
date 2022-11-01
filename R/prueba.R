compara <- function (seq1,seq2) {
  
  par(mfrow=c(1,2))
  barplot(table(seq1), col = 1:4)
  barplot(table(seq2), col = 1:4)
}
setwd("C:/Users/alber/Desktop/COVID-19/Secuencias")
library(seqinr)
SARScorona_virus <- read.fasta("sars_cov_2.fasta")
zika_virus <- read.fasta("zika_virus.fasta")
compara(SARScorona_virus,zika_virus)

