{
  "targets": [
    {
      "target_name": "addon",
      "sources": ["addon.cpp"],
      "cflags!": ["-fno-exceptions"],
      "cflags_cc!": ["-fno-exceptions"],
      "conditions": [
        ["OS=='win'", {
          "defines": ["BUILDING_NODE_EXTENSION"]
        }]
      ],
      "include_dirs": [
        "node_modules/nan",
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}