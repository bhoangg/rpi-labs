#Useful ARM instructions:

mrs: Load value from a system register to one of the general purpose registers (x0–x30)
and: Perform the logical AND operation. We use this command to strip the last byte from the value we obtain from the mpidr_el1 register.
cbz: Compare the result of the previously executed operation to 0 and jump (or branch in ARM terminology) to the provided label if the comparison yields true.
b: Perform an unconditional branch to some label.
adr: Load a label's relative address into the target register.
sub: Subtract values from two registers.
bl: "Branch with a link": perform an unconditional branch and store the return address in x30 (the link register). When the subroutine is finished, use the ret instruction to jump back to the return address.
mov: Move a value between registers or from a constant to a register.