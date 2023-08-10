import { defineConfig } from "vitepress";

// https://vitepress.dev/reference/site-config
export default defineConfig({
  title: "CS Reading",
  description: "计算机书籍",
  srcDir: "./",
  outDir: "./dist",
  lastUpdated: true,
  themeConfig: {
    // https://vitepress.dev/reference/default-theme-config
    nav: [
      { text: "首页", link: "/" },
      { text: "组队学习", link: "/group" },
    ],

    sidebar: [
      {
        text: "目录",
        items: [{ text: "组队学习", link: "/group" }],
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
