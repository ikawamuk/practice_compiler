
# cc0

`cc0` は、C言語のサブセットをターゲットとした自作コンパイラです。
ソースコードから x86_64 インテル形式のアセンブリを生成します。
車輪の"再実装"を通じてコンパイラの仕組みを深く理解することを目的としています。

現在進行中のプロジェクトです。

## 特徴

* **x86_64 出力**: Intel形式のアセンブリを出力し、実際のハードウェア上で動作します。
* **関数・システムコール**: 関数定義や再帰呼び出しに加え、`syscall()` を介したOSとの対話が可能です。

* 現在対応している型が8バイトの符号付き整数のみなので型キーワードがありません。（追加予定）

## 実装済み機能

* **四則演算**: `+`, `-`, `*`, `/` および 優先順位変更の `()`
* **変数**: ローカル変数のスタック割り当て
* **制御構文**: `if` `else` により条件分岐、`while`による繰り返し処理
* **関数制御**: 関数定義、引数、関数呼び出し
* **システムコール**: `syscall()` 関数によるOS機能の直接利用
* **その他演算子**: 正負の符号、比較演算子、アドレス、参照

## コンパイルの流れ

現在はコード生成（アセンブリ出力）までを担当し、実行バイナリの作成には `gcc` を利用しています。

1. **cc0**: `.c` (または独自のソース) → `.s` (x86_64 Assembly)
2. **gcc**: `.s` → 実行バイナリ (Assembler & Linker)

> **今後の展望**: 現在はアセンブル・リンクに `gcc` を使用していますが、将来的にはアセンブラやリンカも自作し、外部ツールに頼らないセルフホスト環境を目指しています。

## 動作例

```c

main() {
	a = 10;
	i = 0;
	while (i < 5)
	{
		a = a + i;
		i = i + 1;
	}
	return (a);
}

```

生成されたファイルを実行すると、終了ステータス `20` を返します。

```c

main()
{
	putchar(104);
	putchar(101);
	putchar(108);
	putchar(108);
	putchar(111);
	putchar(44);
	putchar(32);
	putchar(119);
	putchar(111);
	putchar(114);
	putchar(108);
	putchar(100);
	putchar(33);
	putchar(10);
}

putchar(c)
{
	syscall(1, 1, &c, 1);
}

```

システムコールを呼び出して標準出力に"hello, world!"を出力します。

その他sample_code/にあるソースコードをコンパイルすることができます

## 📚 参考文献

* [低レイヤを知りたい人のためのCコンパイラ作成入門](https://www.sigbus.info/compilerbook)
* [chibiccを読む～Cコンパイラコードリーディング～](https://jupiteroak.hatenablog.com/entry/2023/02/12/180000)

---

## notes

### main
- ファイルの入力がないときはメッセージとUsageを表示する

### run_compiler
- コンパイラのメイン処理。  
ファイル読み取り  
→トークナイズ  
→パース  
→コンパイル  
→アセンブル  
→リンク  
という流れでベルトコンベアのように処理を行うパイプラインアーキテクチャ。
- ファイル読み取りからコンパイルまでのメモリ管理はアリーナアロケータを採用している。
特にパース部で再帰下降解析を用いているため、メモリ開放が複雑にならないようにしたかった。
コンパイル完了以降はファイル名を保持するためでしかメモリ確保をしないのでmallocを使う。

### parse
- 予期せぬトークンが来たときはその場でexitしているが、返り値でエラーを上位に知らせて上位の関数でエラー処理をしたほうがいいかもしれない。その場合は以下のようなresult型を定義してもいいかも。
```c
typedef s_result
{
	enum {
		OK,
		ERROR
	};
	union {
		void	*content,
		char	*error_msg
	};
}	t_result;

```
- expect()の是非。予期したトークンが来たらトークンを一つすすめ、そうでなければ進めない。という多くのパーサーで用いられている関数を使うかどうか迷ったが、個人的に「一つの関数で一つの処理」という大原則を破っているように感じたので採用はしなかった。

- stmtでは現在のトークンをみてwhile, if, blockへ分岐するが、while_stmtなどの中でもこのキーワードはチェックされている。重複した処理になってしまっているが、stmt側のチェックは消費ではなくあくまで分岐のための先読みに近い扱いである。これらは特殊ケースとして早期リターンされreturn文と通常の文がメインの処理になる。

- 構文木のノードはその種類によって子ノードの数や保持するデータが変わるので、無名unionで分けた。block()の実装に現れているように、一つのツリーは各行を表しnextは次の行である。しかし、データ型を与えるときに元プロジェクトの関数のほうが分岐がなく簡素だったかもしれない
```
// chibicc
void visit(Node *node) {
  if (!node)
    return;

  visit(node->lhs);
  visit(node->rhs);
  visit(node->cond);
  visit(node->then);
  visit(node->els);
  visit(node->init);
  visit(node->inc);

  for (Node *n = node->body; n; n = n->next)
    visit(n);
  for (Node *n = node->args; n; n = n->next)
    visit(n);

  switch (node->kind) {
  case ND_MUL:
  case ND_DIV:
  case ND_EQ:
  case ND_NE:
  case ND_LT:
  case ND_LE:
  case ND_VAR:
  case ND_FUNCALL:
  case ND_NUM:
    node->ty = int_type();
    return;
// ...
```
```

void	assign_type(t_func_list *prog)
{
	for (t_func_list *cur = prog; cur; cur = cur->next)
		for (t_tree *node = cur->func->body; node; node = node->next)
			assign_type_recursive(node);
}

static void	assign_type_recursive(t_tree *node)
{
	if (node->next)
		assign_type_recursive(node->next);
	if (node->node_type == ND_LVAR)
	{
		// node->data_type = node->local_var.data_type;
		node->data_type = set_data_type_int(); // 一旦int
		return ;
	}
	// calling new_XX_leaf
	if (node->node_type == ND_NUM || node->node_type == ND_LVAR
	|| node->node_type == ND_FUNC_CALL)
	{
		node->data_type = set_data_type_int();
		return ;
	}
	// calling new_unary
	if (node->node_type == ND_BLOCK || node->node_type == ND_EXPR_STMT
	|| node->node_type == ND_RETURN || node->node_type == ND_ADDRESS
	|| node->node_type == ND_DEREFER || ND_NEG)
	{
		assign_type_recursive(node->child);
		node->data_type = set_data_type_int();
		return ;
	}
	// calling new_binary
	if (ND_ADD <= node->node_type && node->node_type <= ND_ASSIGN)
	{
		assign_type_recursive(node->lhs);
		assign_type_recursive(node->rhs);
		node->data_type = set_data_type_int();
		return ;
	}
	if (node->node_type == ND_IF || node->node_type == ND_WHILE)
	{
		assign_type_recursive(node->cond);
		assign_type_recursive(node->then);
		if (node->els)
			assign_type_recursive(node->els);
		node->data_type = set_data_type_int();
		return ;
	}
}

```

- 関数のローカル変数は宣言された順に単方向リストで保持される。最初に並ぶのは関数の引数である。どこまでが引数かわかるようにt_functionはその関数の引数の数を持つ。

### commpile

- mkstempsを使ってフォーマットされたランダムな.sファイルに書き込みます

- generateはifの羅列ではなくテーブルをもってループする ~~予定！~~ ようにした。

- 関数名がsyscallのときは例外的に引数を専用のレジスタに配置し、syscall命令を行う

- staticなローカル変数label_idxをつかってwhileやifのラベルにユニークなインデックスを与える

- generate_operatorは共通の処理を行いget_op_generatorで関数ポインタを呼ぶことにした。ベタ書きのほうが読みやすいと言われればそうかもしれないのでココの選択は難しいと感じます。

### assemble

- execvpを使ってgccを呼び出しバイナリを作成。

### link

- 第2引数以降にオブジェクトファイルを受取り、gccを用いてリンクします

### library
- セルフホストをするためにはlibcへの依存を最低限にする必要があるという記載を発見。どうせならsyscall()以外のライブラリを封印してかけないか検討中。

- このコンパイラの仕様が固まってないので、ある程度機能ができてセルフホストできそうになってからライブラリを自作し、その後本体をそのライブラリを使う形にリファクタする予定。
