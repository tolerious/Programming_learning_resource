import { defineConfig } from "vitepress";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "CS Reading",
  description: "计算机书籍",
  srcDir: "./",
  outDir: "./cs-reading",
  lastUpdated: true,
  sitemap: {
    hostname: "http://csreading.cn",
    lastmodDateOnly: true,
    transformItems: (items) => {
      items.push({
        url: "/",
        changefreq: "daily",
        priority: 0.9,
      });
    },
  },
  themeConfig: {
    logo:"/logo/png/logo-color.png",
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: "首页", link: "/" },
      { text: "答疑解惑", link: "/group" },
    ],

    sidebar: [
      {
        text: "目录",
        items: [{ text: "答疑解惑", link: "/group" }],
      },
    ],
    socialLinks: [
      {
        icon: "github",
        link: "https://github.com/tolerious/Programming_learning_resource",
      },
    ],
    footer: {
      message: "Powered by Toly with full 💖 ",
      copyright:
        "<a style='color:rgb(255, 124, 10);font-weight:bold;' href='https://englishburning.com/'>如何学习英语？</a>",
    },
  },
});
