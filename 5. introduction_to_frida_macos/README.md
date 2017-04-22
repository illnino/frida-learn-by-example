[Introducción a Frida - SecurityInside.info](http://securityinside.info/introduccion-a-frida/) 西班牙文([Google Translate](https://translate.google.com/translate?sl=auto&tl=en&js=y&prev=_t&hl=en&ie=UTF-8&u=http%3A%2F%2Fsecurityinside.info%2Fintroduccion-a-frida%2F&edit-text=)). 

典型的crackme. 有别于 mobile, 它利用内存地址, 不是很看得懂.


## Built Binary

```bash
gcc poc.c
```


## R2 Analysis
```bash
➜  frida-learning rabin2 -s ./poc
[Symbols]
vaddr=0x100000000 paddr=0x00000000 ord=000 fwd=NONE sz=0 bind=GLOBAL type=FUNC name=__mh_execute_header
vaddr=0x100000dd0 paddr=0x00000dd0 ord=001 fwd=NONE sz=0 bind=GLOBAL type=FUNC name=_encrypt_arg
vaddr=0x100000e60 paddr=0x00000e60 ord=002 fwd=NONE sz=0 bind=GLOBAL type=FUNC name=_main
vaddr=0x100000f1a paddr=0x00000f1a ord=003 fwd=NONE sz=0 bind=LOCAL type=FUNC name=imp.printf
vaddr=0x100000f20 paddr=0x00000f20 ord=004 fwd=NONE sz=0 bind=LOCAL type=FUNC name=imp.scanf
vaddr=0x100000f26 paddr=0x00000f26 ord=005 fwd=NONE sz=0 bind=LOCAL type=FUNC name=imp.srand
vaddr=0x100000f2c paddr=0x00000f2c ord=006 fwd=NONE sz=0 bind=LOCAL type=FUNC name=imp.strcmp
vaddr=0x100000f32 paddr=0x00000f32 ord=007 fwd=NONE sz=0 bind=LOCAL type=FUNC name=imp.strlen
vaddr=0x100000f38 paddr=0x00000f38 ord=008 fwd=NONE sz=0 bind=LOCAL type=FUNC name=imp.time
vaddr=0x100000dd0 paddr=0x00000dd0 ord=009 fwd=NONE sz=0 bind=LOCAL type=FUNC name=func.100000dd0
vaddr=0x100000e60 paddr=0x00000e60 ord=010 fwd=NONE sz=0 bind=LOCAL type=FUNC name=func.100000e60
```

```
// ps 查看 PID
➜ ps
  PID TTY           TIME CMD
17013 ttys001    0:00.03 /Applications/iTerm.app/Contents/MacOS/iTerm2 --server login -fp its
17015 ttys001    0:00.51 -zsh
20605 ttys001    0:00.00 ./poc
15460 ttys002    0:00.03 /Applications/iTerm.app/Contents/MacOS/iTerm2 --server login -fp its
15462 ttys002    0:00.45 -zsh
18074 ttys003    0:00.03 /Applications/iTerm.app/Contents/MacOS/iTerm2 --server login -fp its
18076 ttys003    0:00.74 -zsh
20378 ttys003    0:00.04 r2 ./poc
20007 ttys004    0:00.03 /Applications/iTerm.app/Contents/MacOS/iTerm2 --server login -fp its
20009 ttys004    0:00.33 -zsh

```