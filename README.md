




## test
foo
# bunzo
bar

# hoge
hello, world.


# 参加しよう
## 下準備
コマンド打てる環境をととのえる
apt-get gitとか
githubのアカとる
Bunzoさんに言う
## ssh 公開鍵の設定
 ssh-keygen -t rsa -C "your_email@example.com"
ひたすらエンた
~/.ssh/id_rsa.pubコピる
web経由アカウントセッティングからkey登録する
 ssh -T git@github.com
## checkoutみたいな
 git clone https://github.com/Bunzo/nop
nopってディレクトリできてる
git statusとか打つ
## remote repoの設定
git remote -vとか打つ
 git remote add origin https://github.com/Bunzo/nop
編集
 git commit
 git status
 git push origin master

