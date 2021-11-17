#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>
#include <string>
#include "Tilemap.h"

using namespace sf;
using namespace std;

typedef Vector2f vec2;
typedef Vector2i vec2i;

map<string, vec2i> tile_offsets = {
    { "convex_angle1", {0,0}},    //
    { "convex_angle2", {1,0}},    //

    { "convex_side1", {0,1}},     //
    { "convex_side2", {1,1}},     //

    { "convex_angle3", {0,2}},    //
    { "convex_angle4", {1,2}},    //


    { "forest_NW", {2,0}},        //
    { "forest_N", {3,0}},         //
    { "forest_NE", {4,0}},        //

    { "forest_W", {2,1}},         //
    { "forest_C", {3,1}},         //
    { "forest_E", {4,1}},         //

    { "forest_SW", {2,2}},        //
    { "forest_S", {3,2}},         //
    { "forest_SE", {4,2}},        //

    { "forest_S2", {0,5}},        //


    { "tree_big_1", {0,3}},       //
    { "tree_big_2", {1,3}},       //
    { "tree_big_3", {0,4}},       //
    { "tree_big_4", {1,4}},       //


    { "stump1", {2,3}},           //
    { "stump2", {2,4}},           //
    { "flowers", {3,3}},          //
    { "grass", {1,5}},            //

    { "ground", {4,6}},           //

    { "pool", {3,3}},  //
    { "river_corner_BL", {1,6}},  //
    { "river_corner_BR", {0,6}},  //

    { "river_corner_TR", {2,6}},  //
    { "river_corner_TL", {3,6}},  //

    { "river_vert", {2,5}},       //
    { "river_horiz", {3,5}},      //


    { "tree_base", {4,5}},        //
    { "tree_middle", {4,4}},      //
    { "tree_top", {4,3}},         //
    { "nothing", {0,7}}
};
map<string, string> aliasses = {

    { "A1", "convex_angle1" },
    { "A2", "convex_angle2" },

    { "S1", "convex_side1" },
    { "S2", "convex_side2" },

    { "A3", "convex_angle3" },
    { "A4", "convex_angle4" },


    { "F1", "forest_NW" },
    { "FN", "forest_N" },
    { "F2", "forest_NE" },

    { "FW", "forest_W" },
    { "FC", "forest_C" },
    { "FE", "forest_E" },

    { "F7", "forest_SW" },
    { "FS", "forest_S" },
    { "F4", "forest_SE" },

    { "FZ", "forest_S2" },


    { "T1", "tree_big_1" },
    { "T2", "tree_big_2" },
    { "T3", "tree_big_3" },
    { "T4", "tree_big_4" },


    { "d1", "stump1" },
    { "d2", "stump2" },
    { "FL", "flowers" },
    { "GS", "grass" },

    { "GD", "ground" },
    { "PL", "pool" },

    { "R2", "river_corner_BL" },
    { "R1", "river_corner_BR" },

    { "R3", "river_corner_TR" },
    { "R4", "river_corner_TL" },

    { "RH", "river_horiz" },
    { "RV", "river_vert" },


    { "tb", "tree_base" },
    { "tm", "tree_middle" },
    { "tt", "tree_top" },
    { "--", "nothing" },

};
vector<string> tile_strings = {
    "   GS GS                FW FC A2 -- ",
    "      GS GS       tt    F7 FS S2 -- ",
    "                  tb    tt    FW FC ",
    "   T1 T2    FL          tm    F7 FS ",
    "   T3 T4          GS    tb    F1 FN ",
    "                     F1 FN FN A4 -- ",
    "      R1 R2    F1 FN A4 -- -- -- -- ",
    "R1 RH R4 R3 R2 FW -- -- -- -- -- -- ",
};

void Tilemap::load_level() {
    Tilemap::Tiles;
    Tilemap::groundTiles;
    Sprite ground;
    tiles_texture.loadFromFile("foresttiles2-t.png");
    auto offset = tile_offsets["ground"];
    ground.setTexture(tiles_texture);
    ground.setTextureRect(IntRect(offset *16, { 16,16 }));
    ground.setScale(4, 4);

    int row = 0;
    int scale = 4;
    for (auto& lineMap : tile_strings) {
        for (int i = 0; i < lineMap.length(); ++i) {
            if (i * 3 + 2 >= lineMap.length())
                break;
            string id = lineMap.substr(i * 3, 2);
            if (id == "  ") id = "GD";
            if (aliasses.count(id)) {
                auto name = aliasses[id];
                if (tile_offsets.count(name)) {
                    if (id != "GD") {
                        auto offset = tile_offsets[name];
                        Sprite tile;
                        tile.setTexture(tiles_texture);
                        tile.setTextureRect(IntRect(offset * 16, { 16,16 }));
                        tile.setPosition(vec2(scale * (i * 16), scale * (row * 16)));
                        tile.setScale(4, 4);
                        Tiles.push_back(tile);

                    }
                    auto tile_ground_add = ground;
                    tile_ground_add.setPosition(vec2(scale * (i * 16), scale * (row * 16)));
                    groundTiles.push_back(tile_ground_add);
                }
            }
        }
        row++;
    }
}

void Tilemap::drawMap(sf::RenderWindow& map){
    for (auto& sprite : groundTiles) {
        map.draw(sprite);
    }
    for (auto& sprite : Tiles ) {
        map.draw(sprite);
    }
}
