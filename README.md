# Oblig2IN2140

2 Tasks

2.1 Desgin

  - How to read master file:
  - Any implementation req that are not met
  - Deviations
  - Any tests that fail and why we think so


NOtater rundt metoder (fjernes før obliglevering)

- Load_inodes() Denne skal bare lese inn filen og være uforandret må derfor være readonly for denne. En idee er at inoden denne returnerer er den aller første. SOm vi skal arbeide oss videre fra. Pekeren til denne er root-inode.
- Create_file() enkel node som ikke har behov for noe mer. Jeg antar filer ikke peker til filer på samme måte som dir gjør. 
- Create_dir() Denne blir viktig å implementere da det gir mening at første inode er en dir som inneholder alle andre. Er denne på plass og fungerer som den skal er mye gjort. Og vi er i gang



- må tenke rekursjon på load_nodes() her vil vi lese inn 1 node, så videre på neste og så lenge det er 0 på entries så bare returnere og lese filen som vanlig. Da legge noder på plass i den vi komemr tilbake til. 
