-- Actor definitions go in this directory. (See the example in IntroGame.)

-- circle_actor = {
--   class = "PhysicsActor",
--   shapeType = PhysicsActor_SHAPETYPE_CIRCLE,
--   drawShape = ADS_Circle,
--   color= {0, 1, 0, 0.5},
--   size = 1,
--   name = "CircleActor",
-- }

-- simple_actor = {
--   color= {1, 0, 1, 0.5},
--   size = 5,
--   rotation = 25.0,
--   name = "SimpleActor",
-- }

building = {
  -- density = 0.0,
  tag = "ground",
}

window = {
  color = {0.0, 0.0, 0.0, 1.0},
  size = {6.0, 4.0},
}

platform = {
  class = "PhysicsActor",
  density = 0.0,
  friction = 0.0,
  restitution = 0.0,
  size = {6.0, 2.0},
  tag = "ground, block",
}

orb = {
  class = "Collectible",
  layer = 2,
  tag = "orb",
}

purple_house = {
  layer = 0,
  tag = "purple_house",
  sprite = "Resources/Images/purple_house.png",
  size = {420 / 16, 420 / 16},
}

pine_tree = {
  tag = "pine_tree",
  sprite = "Resources/Images/pine_tree.png",
  size = {15.0, (15.0 * 1.65)},
}

grass = {
  tag = "grass",
  sprite = "Resources/Images/grass.png",
  size = {2.0, (2.0 * (40.0 / 35.0))},
}

shroom = {
  tag = "shroom",
  sprite = "Resources/Images/shroom.png",
  size = {2.0, (2.0 * (34.0 / 39.0))},
}

pine_sapling = {
  tag = "pine_sapling",
  sprite = "Resources/Images/pineSapling.png",
  size = {4.0, 4.0},
}

fence = {
  tag = "fence",
  sprite = "Resources/Images/fence.png",
  size = {3.0, 3.0 * (61.0 / 70.0)},
}

fence_broken = {
  tag = "fence",
  sprite = "Resources/Images/fence_broken.png",
  size = {3.0, 3.0 * (61.0 / 70.0)},
}