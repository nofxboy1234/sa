-- Create house

-- house_01_roof = {
--   def = "building",
--   color = {1.0, 0.0, 0.0, 1.0},
--   size = {16.0, 2.0},
--   position = {0.0, 2.0},
--   layer = 1,
-- }
-- house_01_back_wall = {
--   def = "building",
--   color = {0.5, 1.0, 1.0, 1.0},
--   size = {16.0, 10.0},
--   position = {0.0, -4.0},
--   layer = 1,
-- }

-- window_01 = {
--   def = "window",
--   position = {0.0, -4.0},
--   color = {0.0, 0.1, 0.5, 0.7},
--   layer = 3,
-- }

-- house_01_front_wall_01 = {
--   def = "building",
--   color = {0.5, 1.0, 1.0, 1.0},
--   size = {5.0, 10.0},
--   position = {5.5, -4.0},
--   layer = 3,
-- }

-- house_01_front_wall_02 = {
--   def = "building",
--   color = {0.5, 1.0, 1.0, 1.0},
--   size = {5.0, 10.0},
--   position = {-5.5, -4.0},
--   layer = 3,
-- }

-- house_01_front_wall_03 = {
--   def = "building",
--   color = {0.5, 1.0, 1.0, 1.0},
--   size = {16.0, 3.0},
--   position = {0.0, -0.5},
--   layer = 3,
-- }

-- house_01_front_wall_04 = {
--   def = "building",
--   color = {0.5, 1.0, 1.0, 1.0},
--   size = {16.0, 3.0},
--   position = {0.0, -7.5},
--   layer = 3,
-- }

-- house_01_roof = {
--   def = "platform",
--   color = {1.0, 0.0, 0.0, 1.0},
--   size = {16.0, 2.0},
--   position = {0.0, 2.0},
--   layer = 3,
-- }

-- Create wall

-- rect_01 = {
--   def = "platform",
--   color = {1.0, 1.0, 0.0, 1.0},
--   size = {5.0, 10.0},
--   position = {-30.0, -4.0},
--   layer = 2,
-- }
-- Place platforms

platform_01 = {
  def = "platform",
  color = {1.0, 1.0, 0.0, 1.0},
  position = {35.0, -5.0},
  layer = 2,
}

platform_02 = {
  def = "platform",
  color = {1.0, 1.0, 0.0, 1.0},
  position = {30.0, 2.0},
  layer = 2,
}

platform_03 = {
  def = "platform",
  size = {40.0, 2.0},
  color = {1.0, 1.0, 0.0, 1.0},
  position = {60.0, 15.0},
  layer = 2,
}

platform_04 = {
  def = "platform",
  size = {10.0, 2.0},
  color = {1.0, 1.0, 0.0, 1.0},
  position = {0.0, 30.0},
  layer = 2,
}

platform_05 = {
  def = "platform",
  size = {10.0, 2.0},
  color = {1.0, 1.0, 0.0, 1.0},
  position = {100.0, 20.0},
  layer = 2,
}

platform_06 = {
  def = "platform",
  size = {10.0, 2.0},
  color = {1.0, 1.0, 0.0, 1.0},
  position = {20.0, 25.0},
  layer = 2,
}

-- Place orbs
orb_01 = {
  def = "orb",
  position = {35.0, -3.5},
}

orb_02 = {
  def = "orb",
  position = {30.0, 3.5},
  color = {0.0, 1.0, 0.0, 1.0},
}

orb_03 = {
  def = "orb",
  position = {60.0, 16.5},
  color = {1.0, 0.0, 0.0, 1.0},
}

orb_04 = {
  def = "orb",
  position = {0.0, 31.5},
  color = {0.0, 0.0, 1.0, 1.0},
}

orb_05 = {
  def = "orb",
  position = {100.0, 21.5},
  color = {0.0, 1.0, 1.0, 1.0},
}

orb_06 = {
  def = "orb",
  position = {20.0, 26.5},
  color = {1.0, 0.0, 1.0, 1.0},
}

house_01 = {
  def = "purple_house",
  position = {-100.0, 3.0},
}

pine_tree_01 = {
  layer = 3,
  def = "pine_tree",
  position = {-80.0, 3.0},
}

pine_tree_02 = {
  layer = -1,
  def = "pine_tree",
  position = {-83.0, 3.0},
}

pine_tree_03 = {
  layer = -1,
  def = "pine_tree",
  position = {-88.0, 3.0},
}

grass_01 = {
  layer = 1,
  def = "grass",
  position = {-85.0, -8.0},
}

grass_02 = {
  layer = 1,
  def = "grass",
  position = {-86.0, -8.0},
}

grass_03 = {
  layer = 1,
  def = "grass",
  position = {-88.0, -8.0},
}

grass_04 = {
  layer = 1,
  def = "grass",
  position = {-89.0, -8.0},
}

grass_05 = {
  layer = -1,
  def = "grass",
  position = {-90.0, -8.0},
}

grass_06 = {
  layer = -1,
  def = "grass",
  position = {-91.0, -8.0},
}

grass_07 = {
  layer = -1,
  def = "grass",
  position = {-92.0, -8.0},
}

shroom_01 = {
  layer = 3,
  def = "shroom",
  position = {-107.0, -8.5},
}

pine_sapling_01 = {
  layer = 1,
  def = "pine_sapling",
  position = {-120.0, -7.0},
}

pine_sapling_02 = {
  layer = 1,
  def = "pine_sapling",
  position = {-125.0, -7.0},
}

pine_sapling_03 = {
  layer = 1,
  def = "pine_sapling",
  position = {-130.0, -7.0},
}

pine_sapling_04 = {
  layer = 1,
  def = "pine_sapling",
  position = {-135.0, -7.0},
}

pine_sapling_05 = {
  layer = 1,
  def = "pine_sapling",
  position = {-140.0, -7.0},
}

fence_01 = {
  layer = 2,
  def = "fence",
  position = {-117.0, -8.0},
}

fence_02 = {
  layer = 2,
  def = "fence",
  position = {-119.0, -8.0},
}

fence_03 = {
  layer = 2,
  def = "fence",
  position = {-121.0, -8.0},
}

fence_03 = {
  layer = 2,
  def = "fence",
  position = {-122.0, -8.0},
}

fence_04 = {
  layer = 1,
  def = "fence",
  position = {-124.0, -8.0},
}

fence_05 = {
  layer = 2,
  def = "fence",
  position = {-126.0, -8.0},
}

fence_06 = {
  layer = 2,
  def = "fence",
  position = {-128.0, -8.0},
}

fence_broken_01 = {
  layer = 2,
  def = "fence_broken",
  position = {-132.0, -8.0},
}