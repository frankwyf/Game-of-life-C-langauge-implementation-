# Conway's Game of Life（C + SDL2）

このリポジトリは、過去の授業課題を個人向けオープンソース作品として再構成したものです。

## 概要

C 言語で Conway's Game of Life を実装し、SDL2 による可視化を提供します。

主な機能：

- ファイルからの状態読み込み・保存
- ランダム初期化とクリックによる再設定
- 行数・列数・ステップ数・遅延時間の設定
- リプレイ機能
- Unity ベースの単体テスト

## 構成

- `src/`: アプリ本体コードと実行用アセット
- `test/`: 単体テスト
- `unity/`: Unity テストフレームワーク
- `docs/`: 多言語ドキュメント

## クイックスタート

ビルドと実行：

```bash
cd src
make
./game
```

テスト実行：

```bash
cd test
make
```

## 必要環境

- C コンパイラ（`gcc` または `clang`）
- `make`
- SDL2 開発ライブラリ
- SDL2_ttf 開発ライブラリ

Windows の詳細は `docs/setup/windows.md` を参照してください。

## 操作

- `Backspace`: 盤面を再初期化
- `Enter`: 現在状態からリプレイ
- `Esc`: 実行終了
- 設定モードでマウスクリック: セル状態を切り替え
