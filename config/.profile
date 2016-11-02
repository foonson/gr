#echo ".profile"

RED="\[$(tput setaf 1)\]"
GREEN="\[$(tput setaf 2)\]"
RESET="\[$(tput sgr0)\]"
export PS1="${GREEN}@${RESET} \t ${RED}\u${RESET} \w\n[\#] ${GREEN}$ ${RESET}"

alias psg='ps -eF | grep '

GR=~/gr
alias cdg='cd $GR'
alias cdgc='cd $GR/config'
alias cdgs='cd $GR/scripts'
