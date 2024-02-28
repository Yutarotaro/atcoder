IFS=$'\n'
input=$(</dev/stdin)
IFS=$'\t'
Q=${input[0]}
input=("${input[@]:1}")

array=()

for v in ${input[@]}
do
  if [$]
done