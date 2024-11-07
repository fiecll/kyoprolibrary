---
layout: default
title: 競技プログラミングライブラリ
---

ようこそ！自分用の競技プログラミングライブラリです

## アルゴリズム一覧

<ul>
  {% for algorithm in site.pages %}
    {% if algorithm.path contains 'algorithms/' %}
      <li><a href="{{ algorithm.url | relative_url }}">{{ algorithm.title }}</a></li>
    {% endif %}
  {% endfor %}
</ul>


``
