    .text
# cette directive sert a rendre l'etiquette publique
    .globl update_run_time_isr_wrapper
# debut du traitant
update_run_time_isr_wrapper:
# sauvegarde des registres importants
    pushl %eax
    pushl %edx
    pushl %ecx
# appel a la fonction C realisant le traitant
    call update_run_time_isr
# restauration des registres importants
    popl %ecx
    popl %edx
    popl %eax
# fin du traitant
    iret

