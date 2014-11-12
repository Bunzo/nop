## test
foo
# bunzo
bar

# hoge
hello, world.

## Directory
# simulatr
c simulator
# compiler
compiler
# vlgmodel
verilog model of the processor

# 参加しよう
## 下準備
1. コマンド打てる環境をととのえる
2. apt-get gitとか
3. githubのアカとる
4. Bunzoさんに言う
## ssh 公開鍵の設定
1. ssh-keyつくる
`ssh-keygen -t rsa -C "your_email@example.com"`
    ひたすらエンた
2. ~/.ssh/id_rsa.pubコピる
3. web経由アカウントセッティングからkey登録する
4. 確認
`ssh -T git@github.com`
## checkoutみたいな
`git clone https://github.com/Bunzo/nop`
nopってディレクトリできてる
2. git statusとか打つ
## remote repoの設定
1. git remote -vとか打つ
2. 追加
`git remote add origin https://github.com/Bunzo/nop`
3. 編集
4. local
    git commit [file]
    git status
5. remote
`git push origin master`

