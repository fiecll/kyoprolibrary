# 競技プログラミングライブラリ

ようこそ！ここには競技プログラミング用のアルゴリズムライブラリを掲載しています。

### 概要

ここにサイトの概要や説明を書いてください。

---

---

## アルゴリズム一覧

以下のリンクから各アルゴリズムの詳細ページに移動できます：

{% for algorithm in site.pages %}
  {% if algorithm.path contains 'algorithms/' %}
    - [{{ algorithm.title }}]({{ algorithm.url }})
  {% endif %}
{% endfor %}
